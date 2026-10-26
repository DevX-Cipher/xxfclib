/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Xbox 360 disk layout data structures, moved out of the diskremaining schema family. */
#include "../../xx_format_schema_diskremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdr_xbox_fatx_header_le_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("volume_id","uint32",4,4,SX_ID),
    SX_FIELD("sectors_per_cluster","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("root_cluster","uint32",12,4,SX_NONE),
};
const sx_layout sxdr_xbox_fatx_header_le = {0x607f001dU,"xbox_fatx_header_le",sxdr_xbox_fatx_header_le_fields,SX_COUNT(sxdr_xbox_fatx_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxdr_xbox_fatx_header_be_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("volume_id","uint32",4,4,SX_ID),
    SX_FIELD("sectors_per_cluster","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("root_cluster","uint32",12,4,SX_NONE),
};
const sx_layout sxdr_xbox_fatx_header_be = {0x607f001eU,"xbox_fatx_header_be",sxdr_xbox_fatx_header_be_fields,SX_COUNT(sxdr_xbox_fatx_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxdr_xbox_fatx_name_le_fields[] = {
    SX_FIELD("partition_name_utf16","uint16[32]",0,64,SX_NONE),
};
const sx_layout sxdr_xbox_fatx_name_le = {0x607f0034U,"xbox_fatx_name_le",sxdr_xbox_fatx_name_le_fields,SX_COUNT(sxdr_xbox_fatx_name_le_fields),SX_LE};
#define SXDR_ADD(c,n,p) sxdr_put(c,&sxdr_##n,p,1)
static bool sxdr_xbox(sx_context*c){uint64_t p=UINT64_C(0x130eb0000);uint8_t h[16];if(!sxdr_read(c,p,h,sizeof(h)))return false;bool be=!xx_rt_memcmp(h,"XTAF",4);if(!be&&xx_rt_memcmp(h,"FATX",4))return false;if(!sxdr_put(c,be?&sxdr_xbox_fatx_header_be:&sxdr_xbox_fatx_header_le,p,1))return false;return be||!sxdr_span(c,p+16,64)||SXDR_ADD(c,xbox_fatx_name_le,p+16);}
#undef SXDR_ADD
bool sx_xbox360_layout_build(sx_context*c)
{
 return sxdr_xbox(c);
}
