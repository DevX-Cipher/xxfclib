/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * FMC1 data structures, moved out of the archiveclassic schema family. */
#include "../../xx_format_schema_archiveclassic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxacl_fmc1_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
};
const sx_layout sxacl_fmc1_header = {UINT32_C(0x6050001d),"fmc1_header",sxacl_fmc1_header_fields,SX_COUNT(sxacl_fmc1_header_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_fmc1_member_fields[] = {
 SX_FIELD("name","char[12]",0,12,SX_NONE),
 SX_FIELD("dos_time","uint16",12,2,SX_NONE),
 SX_FIELD("dos_date","uint16",14,2,SX_NONE),
 SX_FIELD("unknown","uint16",16,2,SX_NONE),
 SX_FIELD("reserved","int16",18,2,SX_NONE),
 SX_FIELD("compressed_size","int32",20,4,SX_SIZE),
};
const sx_layout sxacl_fmc1_member = {UINT32_C(0x6050001e),"fmc1_member",sxacl_fmc1_member_fields,SX_COUNT(sxacl_fmc1_member_fields),SX_LE};
bool sx_fmc1_build(sx_context*c)
{
 return sxacl_add(c,&sxacl_fmc1_header,0)&&sxacl_chain(c,&sxacl_fmc1_member,4,24,20,true,false);
}
