/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DPK4 archives data structures, moved out of the archivelegacy schema family. */
#include "../../xx_format_schema_archivelegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxag_dpk_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("archive_size","int32",4,4,SX_SIZE),
 SX_FIELD("directory_size","int32",8,4,SX_SIZE),
 SX_FIELD("entry_count","int32",12,4,SX_COUNT_PROP),
};
const sx_layout sxag_dpk_header = {UINT32_C(0x60250027),"dpk_header",sxag_dpk_header_fields,SX_COUNT(sxag_dpk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxag_dpk_entry_fields[] = {
 SX_FIELD("record_size","int32",0,4,SX_SIZE),
 SX_FIELD("unpacked_size","int32",4,4,SX_SIZE),
 SX_FIELD("packed_size","int32",8,4,SX_SIZE),
 SX_FIELD("data_offset","int32",12,4,SX_OFFSET),
};
const sx_layout sxag_dpk_entry = {UINT32_C(0x60250028),"dpk_entry",sxag_dpk_entry_fields,SX_COUNT(sxag_dpk_entry_fields),SX_LE};
#define SXAG_LIMIT 20000U
static bool sxag_dpk(sx_context *c){uint8_t b[16];if(!sxag_read(c,0,b,16)||!sxag_add(c,&sxag_dpk_header,0))return false;uint64_t n=sxag32(b+12,false),z=sxag32(b+8,false),p=16;if(n>SXAG_LIMIT||!sxag_span(c,p,z))return true;uint64_t end=p+z;for(uint64_t i=0;i<n&&end-p>=16;i++){if(!sxag_read(c,p,b,16))break;uint64_t h=sxag32(b,false);if(h<17||h>end-p)break;if(!sxag_add(c,&sxag_dpk_entry,p))return false;p+=h;}return true;}
bool sx_dpk_build(sx_context*c)
{
 return sxag_dpk(c);
}
