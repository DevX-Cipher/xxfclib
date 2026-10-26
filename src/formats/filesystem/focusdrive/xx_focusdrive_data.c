/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * FocusDrive partition map data structures, moved out of the disklegacy schema family. */
#include "../../xx_format_schema_disklegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdleg_focusdrive_header_fields[] = {
    SX_FIELD("signature","char[14]",0,14,SX_SIGNATURE),
    SX_FIELD("opaque_byte","uint8",14,1,SX_NONE),
    SX_FIELD("partition_count","uint8",15,1,SX_COUNT_PROP),
    SX_FIELD("opaque_identifier","byte[16]",16,16,SX_NONE),
};
const sx_layout sxdleg_focusdrive_header = {0x60750042U,"focusdrive_header",sxdleg_focusdrive_header_fields,SX_COUNT(sxdleg_focusdrive_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_focusdrive_partition_fields[] = {
    SX_FIELD("start_lba","uint32",0,4,SX_NONE),
    SX_FIELD("block_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("opaque_metadata","byte[8]",8,8,SX_NONE),
};
const sx_layout sxdleg_focusdrive_partition = {0x60750043U,"focusdrive_partition",sxdleg_focusdrive_partition_fields,SX_COUNT(sxdleg_focusdrive_partition_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_focusdrive_name_header_fields[] = {
    SX_FIELD("opaque_prefix","byte[4]",0,4,SX_NONE),
    SX_FIELD("unpartitioned_blocks","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("opaque_metadata","byte[24]",8,24,SX_NONE),
};
const sx_layout sxdleg_focusdrive_name_header = {0x60750044U,"focusdrive_name_header",sxdleg_focusdrive_name_header_fields,SX_COUNT(sxdleg_focusdrive_name_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_focusdrive_partition_name_fields[] = {
    SX_FIELD("name","char[32]",0,32,SX_NONE),
};
const sx_layout sxdleg_focusdrive_partition_name = {0x60750045U,"focusdrive_partition_name",sxdleg_focusdrive_partition_name_fields,SX_COUNT(sxdleg_focusdrive_partition_name_fields),SX_LE};
#define SXDLEG_ADD(c,l,p) sxdleg_put(c,&sxdleg_##l,p,1)
#define SXDLEG_TABLE(c,l,p,n) sxdleg_put(c,&sxdleg_##l,p,n)
static bool sxdleg_focus(sx_context*c){uint8_t h[32];if(!sxdleg_read(c,0,h,32)||xx_rt_memcmp(h,"Parsons Engin.",14)||!h[15]||h[15]>30)return false;return SXDLEG_ADD(c,focusdrive_header,0)&&SXDLEG_TABLE(c,focusdrive_partition,32,h[15])&&SXDLEG_ADD(c,focusdrive_name_header,512)&&SXDLEG_TABLE(c,focusdrive_partition_name,544,h[15]);}
#undef SXDLEG_ADD
#undef SXDLEG_TABLE
bool sx_focusdrive_build(sx_context*c)
{
 return sxdleg_focus(c);
}
